#pragma once
#ifndef __BFS_H_
#define __BFS_H_

//#ifdef BFSPRACTICECODE_EXPORTS
//#define BFS_API __declspec(dllexport)
//#else
//#define BFS_API __declspec(dllimport)
//#endif

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

 void getInput();
 void bfs(int, std::vector<int> adj[]);
 void dfs(int, std::vector<int> adj[]);
 void dfsRecursive(int, std::vector<int> adj[]);
#endif
