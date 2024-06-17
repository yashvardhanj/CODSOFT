#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

string taskList[100100];
int status[100100];				// 0->pending //1->completed
int taskIndex = 0;
int command = 1;
string taskName;

void
addTask (string taskName)
{

  taskList[taskIndex] = taskName;
  status[taskIndex] = 0;
  taskIndex++;
}

void
deleteTask (string taskName)
{

  int index_present = -1;
  for (int i = 0; i < taskIndex; i++)
	{
	  if (taskList[i] == taskName)
		{
		  index_present = i;
		  break;
		}
	}
  if (index_present == -1)
	{
	  cout << "The task you mentioned is not present in the list!!" << endl;
	}
  else
	{
	  for (int i = index_present; i < taskIndex - 1; i++)
		{
		  taskList[i] = taskList[i + 1];
		  status[i] = status[i + 1];
		}
	  taskIndex--;
	}
}

void
viewTasks ()
{
  for (int i = 0; i < taskIndex; i++)
	{
	  cout << i << "  " << taskList[i] << "  ";
	  if (status[i] == 0)
		{
		  cout << "pending" << endl;
		}
	  else
		{
		  cout << "completed" << endl;
		}
	}
}

void
changeStatus (string taskName)
{

  int index_present = -1;
  for (int i = 0; i < taskIndex; i++)
	{
	  if (taskList[i] == taskName)
		{
		  index_present = i;
		  break;
		}
	}
  if (index_present == -1)
	{
	  cout << "Task not present" << endl;
	}
  else if (status[index_present] == 0)
	{
	  status[index_present] = 1;
	}
  else
	{
	  status[index_present] = 0;
	}
}


void
printOptions ()
{
  cout << "Press 0 to exit" << endl;
  cout << "Press 1 to add a task to the list" << endl;
  cout << "Press 2 to delete a task" << endl;
  cout << "Press 3 to display the list" << endl;
  cout << "Press 4 to change the status of the task" << endl;
  cin >> command;
}

signed
main ()
{

  printOptions ();
  while (command != 0)
	{

	  switch (command)
		{
		case 1:
		  cout << "Add task: ";

		  cin>>taskName;
		  addTask (taskName);
		  printOptions ();
		  break;
		case 2:

		  cout << "Type the name of the task you want to get deleted: ";
		  cin>>taskName;
		  deleteTask (taskName);
		  printOptions ();
		  break;
		case 3:
		  viewTasks ();
		  printOptions ();
		  break;
		case 4:

		  cout <<
			"Type the name of the task you want to change the status of: ";
		  cin>>taskName;
		  changeStatus (taskName);
		  printOptions ();
		  break;
		default:
		  cout << "Enter a valid input" << endl;
		  printOptions ();
		}
	}
  return 0;
}