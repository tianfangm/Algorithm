#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class student{
private:
    int id;
    static const int ID_MAX = 100001;
public:
    int total_score;
    int num_of_course;
    int perfect_solved;
    vector<int>scores;
    
    student(int num):id(ID_MAX),total_score(0),num_of_course(num),perfect_solved(0)
    {
        scores.resize(num_of_course+1);
        for(int i = 1;i<=num_of_course;++i)
        {
            scores[i]=-1;
        }
    }
    
    bool operator<(const student &other)const
    {
        if(total_score!=other.total_score) return total_score>other.total_score;
        if(perfect_solved!=other.perfect_solved) return perfect_solved>other.perfect_solved;
        return id<other.id;
    }
    
    // 判断是否设置过id
    bool isReset()
    {
        return id!=ID_MAX;
    }
    
    // 打印各科目成绩
    void print()
    {
        printf("%05d %d",id,total_score);
        for(int i = 1;i<=num_of_course;++i)
        {
            if(scores[i]>=0)
            {
                printf(" %d",scores[i]);
            }
            else
            {
                printf(" -");
            }
        }
        printf("\n");
    }
    
    void setCourseScore(int cid,int score)
    {
        scores[cid] = max(score,scores[cid]);
    }
    
    void updateScore()
    {
        for(int i = 1;i<=num_of_course;++i)
        {
            if(scores[i]>0)
            {
                total_score+=scores[i];
            }
        }
    }
    
    void updateScore(const vector<int>&full_scores)
    {
        for(int i = 1;i<=num_of_course;++i)
        {
            if(scores[i]>0)
            {
                total_score+=scores[i];
                if(scores[i]==full_scores[i])
                {
                    perfect_solved+=1;
                }
            }
        }
    }
    
    void setId(int _id)
    {
        id = _id;
    }
};

int main()
{
    int N,K,M;
    scanf("%d %d %d",&N,&K,&M);
    
    vector<int>full_scores(K+1);
    vector<student>students;
    
    for(int i = 0;i<=N;++i)
    {
        students.push_back(student(K));
    }
    
    // 读入各科目满分成绩
    for(int i = 1;i<=K;++i)
    {
        int num = 0;
        scanf("%d",&num);
        full_scores[i]=num;
    }
    
    int listNum = 0;
    for(int i = 0;i<M;++i)
    {
        int id,cid,score;
        scanf("%d %d %d",&id,&cid,&score);
        if(score == -1)
        {
            if(students[id].scores[cid]<0)
            {
                students[id].setCourseScore(cid,0);
            }
            continue;
        }
        if(!students[id].isReset())
        {
            students[id].setId(id);
            ++listNum;
        }
        students[id].setCourseScore(cid,score);
    }
    
    for(int i = 1;i<=N;++i)
    {
        students[i].updateScore(full_scores);
    }
    
    sort(students.begin()+1,students.end());
    
    int last_score = students[1].total_score;
    int rank = 1;
    for(int i = 1;i<=listNum;++i)
    {
        if(students[i].total_score!=last_score)
        {
            rank = i;
            last_score = students[i].total_score;
        }
        printf("%d ",rank);
        students[i].print();
    }
    
    return 0;
}
