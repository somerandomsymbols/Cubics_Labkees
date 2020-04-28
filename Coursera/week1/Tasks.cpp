#include <bits/stdc++.h>

using namespace std;

/*enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;*/
map<string, TasksInfo> M;

class TeamTasks
{
    public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        static TasksInfo g;
        g.clear();

        for (TaskStatus i : {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING, TaskStatus::DONE})
            if (M[person][i])
                g[i] = M[person][i];

        return g;
    }

    void AddNewTask(const string& person)
    {
        if (M.find(person) != M.end())
            M[person][TaskStatus::NEW]++;
        else
            M[person][TaskStatus::NEW] = 1,
            M[person][TaskStatus::IN_PROGRESS] = 0,
            M[person][TaskStatus::TESTING] = 0,
            M[person][TaskStatus::DONE] = 0;
    }

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
    {
        TasksInfo ol, nw;

        if (M.find(person) != M.end())
        {
            int new_tasks = 0;

            for (TaskStatus i : {TaskStatus::NEW, TaskStatus::IN_PROGRESS, TaskStatus::TESTING})
            {
                int h = new_tasks;
                //cout << h << ' ' << M[person][i];
                new_tasks = min(task_count, M[person][i]);
                task_count -= new_tasks;
                M[person][i] -= new_tasks;

                if (M[person][i] != 0)
                    ol[i] = M[person][i];

                M[person][i] += h;

                if (h != 0)
                    nw[i] = h;

                //cout << ' ' << M[person][i] << endl;
            }

            if(new_tasks != 0)
                nw[TaskStatus::DONE] = new_tasks;

            M[person][TaskStatus::DONE] += new_tasks;
        }

        //cout << M[person][TaskStatus::NEW] << endl;
        return tuple<TasksInfo, TasksInfo>(nw, ol);
    }
};

void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  TasksInfo updated_tasks, untouched_tasks;

  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }
  cout << "Alice's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  cout << "Updated Alice's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Alice's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 5);
  cout << "Updated Alice's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Alice's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 1);
  cout << "Updated Alice's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Alice's tasks: ";
  PrintTasksInfo(untouched_tasks);

  for (int i = 0; i < 5; ++i) {
    tasks.AddNewTask("Alice");
  }

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 2);
  cout << "Updated Alice's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Alice's tasks: ";
  PrintTasksInfo(untouched_tasks);

  cout << "Alice's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Alice", 4);
  cout << "Updated Alice's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Alice's tasks: ";
  PrintTasksInfo(untouched_tasks);

  cout << "Alice's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

  return 0;
}
