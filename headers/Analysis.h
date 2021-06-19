//
//  Analysis.h
//  FemCourse
//
//  Created by Philippe Devloo on 08/05/18.
//

#ifndef Analysis_h
#define Analysis_h


#include "DataTypes.h"
///\cond
#include <string>
#include <iostream>
///\endcond
//#include <armadillo>
//using namespace arma;

class CompMesh;

class PostProcess;

/**
 @defgroup global
 @brief Classes that orchestrate the computation of a finite element approximation
 */

/**
 @brief Performs a finite element computation and performs post processing
 @ingroup global
 
 Combines a computational mesh, an assembly process and matrix inversion to compute a finite element approximation
 */
class Analysis
{
protected:
    CompMesh *cmesh;
    
    MatrixDouble Solution;
    
    MatrixDouble GlobalSystem;
    
    MatrixDouble RightHandSide;
    
public:
    
    Analysis();
    
    Analysis(const Analysis &cp);
    
    Analysis &operator=(const Analysis &cp);
    
    ~Analysis();
    
    Analysis(CompMesh *cmesh);
    
    void SetMesh(CompMesh *cmesh);
    
    CompMesh *Mesh() const;
    
    void RunSimulation();
    
    void PostProcessSolution(const std::string &filename, PostProcess &defPostProc) const;
    
    VecDouble PostProcessError(std::ostream &out, PostProcess &defPostProc) const;
    
};

#endif /* Analysis_h */
