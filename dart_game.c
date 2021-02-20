#include <stdio.h>
#include <stdlib.h>
int descript_seg_and_ring(int segment_value,char ring)
{
if(ring=='S')
{int point_value=segment_value;
return point_value;
}
else if(ring=='D')
{int point_value=segment_value*2;
return point_value;
}
else if(ring=='T')
{int point_value=segment_value*3;
return point_value;
}
else if(ring=='O')
{int point_value=25;
return point_value;
}
else if(ring=='I')
{int point_value=50;
return point_value;
}
else
{return 0;
}
}


int calculate_rem_point(int current_point,int segment_value,char ring,int target)
{if(current_point==target) //for starting the game
{   if(ring=='D')
    {int remaining_point=current_point-descript_seg_and_ring(segment_value,ring);
    return remaining_point;
    }
    else
    {int remaining_point=current_point;
    return remaining_point;
    }
}

else
{int checking_point=current_point-descript_seg_and_ring(segment_value,ring);
    if(checking_point==0 && ring!='D') //for ending the game
    {int remaining_point=current_point;
     return remaining_point;
    }
    else if(checking_point<0 || checking_point==1) //for ending the game
    {int remaining_point=current_point;
     return remaining_point;
    }
    else
    {int remaining_point=checking_point;
     return remaining_point;
    }
}
}

int main()
{
int target;
int segment;
char area;
printf("Target: ");
scanf("%d",&target);
int current_point=target;

while(current_point!=0)
{printf("Throw: ");
scanf("%d %c",&segment,&area);
int points=calculate_rem_point(current_point,segment,area,target);
printf("Points: %d\n",points);
current_point=points;
}

return EXIT_SUCCESS;
}
