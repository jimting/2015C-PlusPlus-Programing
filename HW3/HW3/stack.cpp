#include "stack.h"
const point shape[7][4] = {{ point(-1,0),point(0,0)	,point(0,1)	,point(0,2)	},{ point(0,0)	,point(1,0)	,point(0,1)	,point(0,2)	},{ point(0,0)	,point(0,1)	,point(0,2)	,point(0,3)	},{ point(0,0)	,point(0,1)	,point(0,2)	,point(1,1)	},{ point(0,0)	,point(1,0)	,point(0,1)	,point(1,1)	},{ point(0,1)	,point(0,0)	,point(1,1)	,point(1,2)	},{ point(0,1)	,point(0,2)	,point(1,1)	,point(1,0)	}};
const int orgX = 10, orgY = 5, width = 25, height = 16;
stack::stack(void)
{
}

stack::~stack(void)
{
}


