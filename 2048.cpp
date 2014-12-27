#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;
class M2048
{
	int a[4][4];
	int score;
	int motionfl;
	public:
		M2048()
		{
			score=0;
			motionfl=0;
		}
		void zero()
		{
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					a[i][j]=0;
					score=0;
					motionfl=0;
				return;
		}
		void display()
		{
			for(int i=0;i<4;i++)
			{
					for(int j=0;j<4;j++)
						cout<<a[i][j]<<"\t";
				cout<<endl<<endl;
			}
			cout<<" your score is : "<<score<<endl;
			cout<<"\t________________________________________"<<endl<<endl;
			return;
		}
					
		void generate()
		{
			srand(time(0));
			int tot=0, i=0,j=0;
			tot=rand()%2;  		
			while(a[i][j]!=0) 
				{	i=rand()%4;
					j=rand()%4;
				}
				if(tot==1)
				a[i][j]=1;
				else 
				a[i][j]=3;
		}
		void generatebeg()
		{
			int tot=0,i=0,j=0;
			tot=rand()%2;  
			i=rand()%4;
			j=rand()%4;
			if(tot==1)
				a[i][j]=1;
			else 
				a[i][j]=3;
			tot=rand()%2;
			i=rand()%4;
			j=rand()%4;	
			while(a[i][j]!=0) 
				{	i=rand()%4;
					j=rand()%4;
				}
			if(tot==1)
				a[i][j]=1;
			else 
				a[i][j]=3;
		}
		bool isadd(int a,int b)
		{
			if(a>3&&b>3)
			return (a==b);
			else 
			return ((a+b)==4);
		}
		
	void	mu(int i)
	{
		int fl,pos,count;
						fl=0;
						
						for(int j=0;j<3;j++)
						{
							if(a[j][i]==0)
							{
							
								fl=1;
								pos=j;
								break;
							}
						}
						if(fl)
						{
							
							for(int j=pos;j<3;j++)      //moving upwards for initial zeroes.(0 0 0 1)
							{
								if(a[pos][i]!=0)
									motionfl=1;
								a[pos++][i]=a[j+1][i];
							}
							a[3][i]=0;
						}
					}
		void	md(int i)
	{
		int fl,pos,count;
						fl=0;
						
						for(int j=3;j>0;j--)
						{
							if(a[j][i]==0)
							{
								
								fl=1;
								pos=j;
								break;
							}
						}
						if(fl)
						{
							
							for(int j=pos;j>0;j--)      //moving upwards for initial zeroes.(0 0 0 1)
							{
								if(a[pos][i]!=0)
									motionfl=1;
								a[pos--][i]=a[j-1][i];
									
							}
							a[0][i]=0;
						}
	}//checked
	
		void	ml(int i)
	{
		int fl,pos,count;
						fl=0;
						
						for(int j=0;j<3;j++)
						{
							if(a[i][j]==0)
							{
							
								fl=1;
								pos=j;
								break;
							}
						}
						if(fl)
						{
							
							for(int j=pos;j<3;j++)      //moving rightwards for initial zeroes.(1 0 0 1)
							{
								if(a[i][pos]!=0)
									motionfl=1;
								a[i][pos++]=a[i][j+1];
							}
							a[i][3]=0;
						}
					}
	void	mr(int i)
	{
		int fl,pos,count;
						fl=0;
						
						for(int j=3;j>0;j--)
						{
							if(a[i][j]==0)
							{
							
								fl=1;
								pos=j;
								break;
							}
						}
						if(fl)
						{
							
							for(int j=pos;j>0;j--)      //moving upwards for initial zeroes.(0 0 0 1)
							{
								if(a[i][pos]!=0)
									motionfl=1;
								a[i][pos--]=a[i][j-1];
							}
							a[i][0]=0;
						}
	}//checked
		void move(char choice)
		{
			 motionfl=0;
			switch(choice)
			{
				case 'W':
				case 'w':
					for(int i=0;i<4;i++)
					{
						for(int j=0;j<3;j++)
							mu(i);
					
					for(int k=0;k<3;k++)
						{
							for(int l=k+1;l<4;l++)
							{
								if(a[l][i]!=0)
								{
									if(isadd(a[k][i],a[l][i]))// checking adding
									{
										motionfl=1;
										score+=a[k][i]+a[l][i];
										a[k][i]+=a[l][i];
										a[l][i]=0;	
									}
								}
								mu(i);							//moving upwards
							} 
						}
					}
					break;
			case 's' :
			case 'S':
				for(int i=0;i<4;i++)
					{
						for(int j=3;j>0;j--)
							md(i);
					
					for(int k=3;k>0;k--)
						{
							for(int l=k-1;l>=0;l--)
							{
								if(a[l][i]!=0)
								{
									if(isadd(a[k][i],a[l][i]))// checking adding
									{
										motionfl=1;
										score+=a[k][i]+a[l][i];
										a[k][i]+=a[l][i];
										a[l][i]=0;	
									}
								}
								md(i);							//moving downwards
							} 
						}
					}
					break;
				case 'A':
				case 'a':
					for(int i=0;i<4;i++)
					{
						for(int j=0;j<3;j++)
							ml(i);
					
					for(int k=0;k<3;k++)
						{
							for(int l=k+1;l<4;l++)
							{
								if(a[i][l]!=0)
								{	
									if(isadd(a[i][k],a[i][l]))// checking adding
									{
										motionfl=1;
										score+=a[i][k]+a[i][l];
										a[i][k]+=a[i][l];
										a[i][l]=0;	
									}
								}
								ml(i);							//moving leftwards
							} 
						}
					}
					break;
			case 'D' :
			case 'd':
				for(int i=0;i<4;i++)
					{
						for(int j=3;j>0;j--)
							mr(i);
					
					for(int k=3;k>0;k--)
						{
							for(int l=k-1;l>=0;l--)
							{
								if(a[i][l]!=0)
								{
									
									if(isadd(a[i][k],a[i][l]))// checking adding
									{
										motionfl=1;
										score+=a[i][k]+a[i][l];
										a[i][k]+=a[i][l];
										a[i][l]=0;	
									}
								}
								mr(i);							//moving rightwards
							} 
						}
					}
					break;
					
		}
	}			
		bool iswin()				//checks if user wins or not
		{
			for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
						if(a[i][j]==2048)
							return true;
				}
				return false;
		}
		bool isempty()				//checks if any place is empty or not
		{
			int fl=0;
			for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
						{
							if(a[i][j]==0)
								{
									fl=1;
									break;
								}
						}
				}
				if(fl)
					return true;
				else return false;
		}
			
		bool gameover()			//checks if game is over or not.
		{
			if(isempty())
			return false;
			else
			{
				int fl=0;
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(isadd(a[j][i],a[j+1][i]))
							return false;
					}
				}
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<3;j++)
					{
						if(isadd(a[i][j],a[i][j+1]))
							return false;
					}
				}
				return true;
			}
		}
		void play()
		{
			char ch,choice;
			zero();
			generatebeg();
			cout<<endl<<endl;
			display();
			while(!(iswin()||gameover()))
			{
				cout<<"enter your choice: \n\t 1. W for up \n\t2. S for down \n\t3. A for right \n\t4. D for left: "<<endl;
				cout<<"your choice is:    ";
				cin>>ch;
				cout<<endl<<endl;;
				move(ch);
				if(motionfl==1)
					generate();
				display();
			}
			if(iswin())
			{
				 choice=0;
				cout<<"Hurray you won the game. \n\t 1.continue 2. Tryagain"<<endl;
				cin>>choice;
				if(choice==2)
				exit(-1);
				else
				{
					while(!(gameover()))
					{
						cout<<"enter your choice: \n\t 1. W for up \n\t2. S for down \n\t3. A for right \n\t4. D for left: "<<endl;
						cin>>ch;
						move(ch);
						if(motionfl==1)
						generate();
						display();
					}
				}
			}
			else if(gameover())
			{
				choice=0;
				cout<<"GAME OVER!!!. 1.Wish to try again 2.Exit"<<endl;
				cin>>choice;
				if(choice==2)
				exit(-1);
				else if(choice==1)
				{
					play();
				}
				else 
					{
						cout<<"invalid input!!!!. Aborting."<<endl;
						exit(-1);
					}
			}
						
				return;
		}
	};
	int main()
	{
		cout<<rand()<<endl;
		system("color f1");
		M2048 game;
		game.play();
		return 0;
	}
			
