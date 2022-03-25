
class obj
{
	public:
		int x;
		int y;
		int w;
		int h;
		int color;
};

int colision(obj o1, obj o2)
{
	if(o1.w > o2.x && o1.x < o2.w)
	{
		if(o1.h > o2.y && o1.y < o2.h)
		{
			return 1;
		}
	}
	
	return 0;
}
