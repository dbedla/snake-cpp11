#include <frame.h>

CFrame::~CFrame()
{

}

CFrame::CFrame()
{
    struct winsize terminal_properties;
    ioctl(0, TIOCGWINSZ, &terminal_properties);

    int height = (MIN_SCREEN_HEIGHT > terminal_properties.ws_row-1) ?
                MIN_SCREEN_HEIGHT : terminal_properties.ws_row-1;
    int widith  = (MIN_SCREEN_WIDITH > terminal_properties.ws_col) ?
                MIN_SCREEN_WIDITH : terminal_properties.ws_col;

    for(int i=0; i<height; i++ )
    {
        _frame.push_back( std::vector<char>(widith,EMPTY_FIELD) );
    }

}


unsigned int CFrame::getWidith()
{
    return _frame[0].size();
}

unsigned int CFrame::getHeight()
{
    return _frame.size();
}

void CFrame::SetPoint(const CPoint p, char c)
{
    // revert point index because of optymization for
    // frame store in memory (fast and easy drawing)
    _frame[p._y][p._x] = c;
}


void CFrame::drawFrame()
{

    for(auto y = _frame.begin(); y < _frame.end(); y++)
    {
        for(auto x = y->begin(); x< y->end(); x++)
        {
            std::cout<<*x;
        }
        std::cout<<std::endl;
    }
}

void CFrame::clearFrame()
{
    auto clear = [] (std::vector<char> &line){ line.assign(line.size(), EMPTY_FIELD);};
    std::for_each(_frame.begin(), _frame.end(), clear );
}


void CFrame::drawObjIntoFrame(const IFrameElement<PointsList >& obj, GraphicalRepresentation graphPointRep)
{
    auto elements = obj.getFrameElements();

    std::for_each(elements.begin(), elements.end(),
                  [&](CPoint &p){_frame[p._y][p._x] = graphPointRep;});
}
