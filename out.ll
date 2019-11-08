target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.14.0"

%struct.bst = type { i32, %struct.bst*, %struct.bst*}

define %struct.bst* @insert(%struct.bst*, i32) {
 entry:
  %2 = alloca %struct.bst*, align 8
  %3 = alloca i32, align 4
  store %struct.bst* %0, %struct.bst** %2, align 8
  store i32 %1, i32* %3, align 4
  %4 = load %struct.bst*, %struct.bst** %2, align 8
  %5 = icmp ne %struct.bst*  %4, null
  br i1 %5, label %L0, label %L1

 L0:
  %6 = load i32, i32* %3, align 4
  %7 = load %struct.bst*, %struct.bst** %2, align 8
  %8 = getelementptr inbounds %struct.bst, %struct.bst* %7, i32 0, i32 0
  %9 = load i32, i32* %8
  %10 = icmp slt i32  %6,  %9 
  br i1 %10, label %L3, label %L4

 L3:
  %11 = load %struct.bst*, %struct.bst** %2, align 8
  %12 = getelementptr inbounds %struct.bst, %struct.bst* %11, i32 0, i32 1
  %13 = load %struct.bst*, %struct.bst** %12
  %14 = load i32, i32* %3, align 4
  %15 = call %struct.bst* @insert(%struct.bst* %13, i32 %14)
  %16 = load %struct.bst*, %struct.bst** %2, align 8
  %17 = getelementptr inbounds %struct.bst, %struct.bst* %16, i32 0, i32 1
  store %struct.bst* %15, %struct.bst** %17, align 8
  br label %L5

 L4:
  %18 = load i32, i32* %3, align 4
  %19 = load %struct.bst*, %struct.bst** %2, align 8
  %20 = getelementptr inbounds %struct.bst, %struct.bst* %19, i32 0, i32 0
  %21 = load i32, i32* %20
  %22 = icmp sgt i32  %18,  %21 
  br i1 %22, label %L6, label %L7

 L6:
  %23 = load %struct.bst*, %struct.bst** %2, align 8
  %24 = getelementptr inbounds %struct.bst, %struct.bst* %23, i32 0, i32 2
  %25 = load %struct.bst*, %struct.bst** %24
  %26 = load i32, i32* %3, align 4
  %27 = call %struct.bst* @insert(%struct.bst* %25, i32 %26)
  %28 = load %struct.bst*, %struct.bst** %2, align 8
  %29 = getelementptr inbounds %struct.bst, %struct.bst* %28, i32 0, i32 2
  store %struct.bst* %27, %struct.bst** %29, align 8
  br label %L7
 L7:
  br label %L5

 L5:
  br label %L2

 L1:
  %30 = call i8* @malloc(i64 32)
  %31 = bitcast i8* %30 to %struct.bst*
  store %struct.bst* %31, %struct.bst** %2, align 8
  %32 = load i32, i32* %3, align 4
  %33 = load %struct.bst*, %struct.bst** %2, align 8
  %34 = getelementptr inbounds %struct.bst, %struct.bst* %33, i32 0, i32 0
  store i32 %32, i32* %34, align 4
  %35 = load %struct.bst*, %struct.bst** %2, align 8
  %36 = getelementptr inbounds %struct.bst, %struct.bst* %35, i32 0, i32 1
  store %struct.bst* null, %struct.bst** %36, align 8
  %37 = load %struct.bst*, %struct.bst** %2, align 8
  %38 = getelementptr inbounds %struct.bst, %struct.bst* %37, i32 0, i32 2
  store %struct.bst* null, %struct.bst** %38, align 8
  br label %L2

 L2:
  %39 = load %struct.bst*, %struct.bst** %2, align 8
  ret %struct.bst* %39
}

define %struct.bst* @inorderPredecessor(%struct.bst*) {
 entry:
  %1 = alloca %struct.bst*, align 8
  store %struct.bst* %0, %struct.bst** %1, align 8
  br label %L8

 L8:
  %2 = load %struct.bst*, %struct.bst** %1, align 8
  %3 = getelementptr inbounds %struct.bst, %struct.bst* %2, i32 0, i32 2
  %4 = load %struct.bst*, %struct.bst** %3
  %5 = icmp ne %struct.bst*  %4, null
  br i1 %5, label %L9, label %L10

 L9:
  %6 = load %struct.bst*, %struct.bst** %1, align 8
  %7 = getelementptr inbounds %struct.bst, %struct.bst* %6, i32 0, i32 2
  %8 = load %struct.bst*, %struct.bst** %7
  store %struct.bst* %8, %struct.bst** %1, align 8
  br label %L8

 L10:
  %9 = load %struct.bst*, %struct.bst** %1, align 8
  ret %struct.bst* %9
}

define %struct.bst* @bst_del(%struct.bst*, i32) {
 entry:
  %2 = alloca %struct.bst*, align 8
  %3 = alloca i32, align 4
  %4 = alloca %struct.bst*, align 8
  %5 = alloca %struct.bst*, align 8
  store %struct.bst* %0, %struct.bst** %2, align 8
  store i32 %1, i32* %3, align 4
  %6 = load %struct.bst*, %struct.bst** %2, align 8
  store %struct.bst* %6, %struct.bst** %5, align 8
  %7 = load %struct.bst*, %struct.bst** %2, align 8
  %8 = getelementptr inbounds %struct.bst, %struct.bst* %7, i32 0, i32 0
  %9 = load i32, i32* %8
  %10 = load i32, i32* %3, align 4
  %11 = icmp eq i32  %9,  %10 
  br i1 %11, label %L11, label %L12

 L11:
  %12 = load %struct.bst*, %struct.bst** %2, align 8
  %13 = getelementptr inbounds %struct.bst, %struct.bst* %12, i32 0, i32 1
  %14 = load %struct.bst*, %struct.bst** %13
  %15 = icmp eq %struct.bst*  %14, null
  br i1 %15, label %L14, label %L15

 L14:
  %16 = load %struct.bst*, %struct.bst** %2, align 8
  %17 = getelementptr inbounds %struct.bst, %struct.bst* %16, i32 0, i32 2
  %18 = load %struct.bst*, %struct.bst** %17
  %19 = icmp eq %struct.bst*  %18, null
  br i1 %19, label %L17, label %L18

 L17:
  store %struct.bst* null, %struct.bst** %5, align 8
  br label %L19

 L18:
  %20 = load %struct.bst*, %struct.bst** %2, align 8
  %21 = getelementptr inbounds %struct.bst, %struct.bst* %20, i32 0, i32 2
  %22 = load %struct.bst*, %struct.bst** %21
  store %struct.bst* %22, %struct.bst** %5, align 8
  br label %L19

 L19:
  br label %L16

 L15:
  %23 = load %struct.bst*, %struct.bst** %2, align 8
  %24 = getelementptr inbounds %struct.bst, %struct.bst* %23, i32 0, i32 2
  %25 = load %struct.bst*, %struct.bst** %24
  %26 = icmp eq %struct.bst*  %25, null
  br i1 %26, label %L20, label %L21

 L20:
  %27 = load %struct.bst*, %struct.bst** %2, align 8
  %28 = getelementptr inbounds %struct.bst, %struct.bst* %27, i32 0, i32 1
  %29 = load %struct.bst*, %struct.bst** %28
  store %struct.bst* %29, %struct.bst** %5, align 8
  br label %L22

 L21:
  %30 = load %struct.bst*, %struct.bst** %2, align 8
  %31 = getelementptr inbounds %struct.bst, %struct.bst* %30, i32 0, i32 1
  %32 = load %struct.bst*, %struct.bst** %31
  %33 = call %struct.bst* @inorderPredecessor(%struct.bst* %32)
  store %struct.bst* %33, %struct.bst** %4, align 8
  %34 = load %struct.bst*, %struct.bst** %4, align 8
  %35 = getelementptr inbounds %struct.bst, %struct.bst* %34, i32 0, i32 0
  %36 = load i32, i32* %35
  %37 = load %struct.bst*, %struct.bst** %2, align 8
  %38 = getelementptr inbounds %struct.bst, %struct.bst* %37, i32 0, i32 0
  store i32 %36, i32* %38, align 4
  %39 = load %struct.bst*, %struct.bst** %2, align 8
  %40 = getelementptr inbounds %struct.bst, %struct.bst* %39, i32 0, i32 1
  %41 = load %struct.bst*, %struct.bst** %40
  %42 = load %struct.bst*, %struct.bst** %4, align 8
  %43 = getelementptr inbounds %struct.bst, %struct.bst* %42, i32 0, i32 0
  %44 = load i32, i32* %43
  %45 = call %struct.bst* @bst_del(%struct.bst* %41, i32 %44)
  %46 = load %struct.bst*, %struct.bst** %2, align 8
  %47 = getelementptr inbounds %struct.bst, %struct.bst* %46, i32 0, i32 1
  store %struct.bst* %45, %struct.bst** %47, align 8
  br label %L22

 L22:
  br label %L16

 L16:
  br label %L13

 L12:
  %48 = load %struct.bst*, %struct.bst** %2, align 8
  %49 = getelementptr inbounds %struct.bst, %struct.bst* %48, i32 0, i32 0
  %50 = load i32, i32* %49
  %51 = load i32, i32* %3, align 4
  %52 = icmp sge i32  %50,  %51 
  br i1 %52, label %L23, label %L24

 L23:
  %53 = load %struct.bst*, %struct.bst** %2, align 8
  %54 = getelementptr inbounds %struct.bst, %struct.bst* %53, i32 0, i32 1
  %55 = load %struct.bst*, %struct.bst** %54
  %56 = load i32, i32* %3, align 4
  %57 = call %struct.bst* @bst_del(%struct.bst* %55, i32 %56)
  %58 = load %struct.bst*, %struct.bst** %2, align 8
  %59 = getelementptr inbounds %struct.bst, %struct.bst* %58, i32 0, i32 1
  store %struct.bst* %57, %struct.bst** %59, align 8
  br label %L25

 L24:
  %60 = load %struct.bst*, %struct.bst** %2, align 8
  %61 = getelementptr inbounds %struct.bst, %struct.bst* %60, i32 0, i32 2
  %62 = load %struct.bst*, %struct.bst** %61
  %63 = load i32, i32* %3, align 4
  %64 = call %struct.bst* @bst_del(%struct.bst* %62, i32 %63)
  %65 = load %struct.bst*, %struct.bst** %2, align 8
  %66 = getelementptr inbounds %struct.bst, %struct.bst* %65, i32 0, i32 2
  store %struct.bst* %64, %struct.bst** %66, align 8
  br label %L25

 L25:
  br label %L13

 L13:
  %67 = load %struct.bst*, %struct.bst** %5, align 8
  ret %struct.bst* %67
}

define i32 @inOrder(%struct.bst*) {
 entry:
  %1 = alloca %struct.bst*, align 8
  store %struct.bst* %0, %struct.bst** %1, align 8
  %2 = load %struct.bst*, %struct.bst** %1, align 8
  %3 = icmp ne %struct.bst*  %2, null
  br i1 %3, label %L26, label %L27

 L26:
  %4 = load %struct.bst*, %struct.bst** %1, align 8
  %5 = getelementptr inbounds %struct.bst, %struct.bst* %4, i32 0, i32 1
  %6 = load %struct.bst*, %struct.bst** %5
  %7 = call i32 @inOrder(%struct.bst* %6)
  store i32 %7, i32* @in, align 4
  %8 = load %struct.bst*, %struct.bst** %1, align 8
  %9 = getelementptr inbounds %struct.bst, %struct.bst* %8, i32 0, i32 0
  %10 = load i32, i32* %9
  %11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %10)
  %12 = load %struct.bst*, %struct.bst** %1, align 8
  %13 = getelementptr inbounds %struct.bst, %struct.bst* %12, i32 0, i32 2
  %14 = load %struct.bst*, %struct.bst** %13
  %15 = call i32 @inOrder(%struct.bst* %14)
  store i32 %15, i32* @in, align 4
  br label %L27
 L27:
  ret i32 1
}

define i32 @preOrder(%struct.bst*) {
 entry:
  %1 = alloca %struct.bst*, align 8
  store %struct.bst* %0, %struct.bst** %1, align 8
  %2 = load %struct.bst*, %struct.bst** %1, align 8
  %3 = icmp ne %struct.bst*  %2, null
  br i1 %3, label %L28, label %L29

 L28:
  %4 = load %struct.bst*, %struct.bst** %1, align 8
  %5 = getelementptr inbounds %struct.bst, %struct.bst* %4, i32 0, i32 0
  %6 = load i32, i32* %5
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %6)
  %8 = load %struct.bst*, %struct.bst** %1, align 8
  %9 = getelementptr inbounds %struct.bst, %struct.bst* %8, i32 0, i32 1
  %10 = load %struct.bst*, %struct.bst** %9
  %11 = call i32 @preOrder(%struct.bst* %10)
  store i32 %11, i32* @in, align 4
  %12 = load %struct.bst*, %struct.bst** %1, align 8
  %13 = getelementptr inbounds %struct.bst, %struct.bst* %12, i32 0, i32 2
  %14 = load %struct.bst*, %struct.bst** %13
  %15 = call i32 @preOrder(%struct.bst* %14)
  store i32 %15, i32* @in, align 4
  br label %L29
 L29:
  ret i32 1
}

define i32 @postOrder(%struct.bst*) {
 entry:
  %1 = alloca %struct.bst*, align 8
  store %struct.bst* %0, %struct.bst** %1, align 8
  %2 = load %struct.bst*, %struct.bst** %1, align 8
  %3 = icmp ne %struct.bst*  %2, null
  br i1 %3, label %L30, label %L31

 L30:
  %4 = load %struct.bst*, %struct.bst** %1, align 8
  %5 = getelementptr inbounds %struct.bst, %struct.bst* %4, i32 0, i32 1
  %6 = load %struct.bst*, %struct.bst** %5
  %7 = call i32 @postOrder(%struct.bst* %6)
  store i32 %7, i32* @in, align 4
  %8 = load %struct.bst*, %struct.bst** %1, align 8
  %9 = getelementptr inbounds %struct.bst, %struct.bst* %8, i32 0, i32 2
  %10 = load %struct.bst*, %struct.bst** %9
  %11 = call i32 @postOrder(%struct.bst* %10)
  store i32 %11, i32* @in, align 4
  %12 = load %struct.bst*, %struct.bst** %1, align 8
  %13 = getelementptr inbounds %struct.bst, %struct.bst* %12, i32 0, i32 0
  %14 = load i32, i32* %13
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %14)
  br label %L31
 L31:
  ret i32 1
}

define i32 @main() {
 entry:
  %0 = alloca i32, align 4
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca %struct.bst*, align 8
  store i32 0, i32* %0, align 4
  %4 = getelementptr inbounds [17 x i8], [17 x i8]* @.str.4, i32 0, i32 0
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i8* %4)
  store %struct.bst* null, %struct.bst** %3, align 8
  %6 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %1)
  br label %L32

 L32:
  %7 = load i32, i32* %1, align 4
  %8 = icmp ne i32  %7, 0 
  br i1 %8, label %L33, label %L34

 L33:
  %9 = load %struct.bst*, %struct.bst** %3, align 8
  %10 = load i32, i32* %1, align 4
  %11 = call %struct.bst* @insert(%struct.bst* %9, i32 %10)
  store %struct.bst* %11, %struct.bst** %3, align 8
  %12 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %1)
  br label %L32

 L34:
  %13 = getelementptr inbounds [8 x i8], [8 x i8]* @.str.5, i32 0, i32 0
  %14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i8* %13)
  %15 = load %struct.bst*, %struct.bst** %3, align 8
  %16 = call i32 @inOrder(%struct.bst* %15)
  store i32 %16, i32* @in, align 4
  %17 = getelementptr inbounds [9 x i8], [9 x i8]* @.str.6, i32 0, i32 0
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i8* %17)
  %19 = load %struct.bst*, %struct.bst** %3, align 8
  %20 = call i32 @preOrder(%struct.bst* %19)
  store i32 %20, i32* @in, align 4
  %21 = getelementptr inbounds [10 x i8], [10 x i8]* @.str.7, i32 0, i32 0
  %22 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i8* %21)
  %23 = load %struct.bst*, %struct.bst** %3, align 8
  %24 = call i32 @postOrder(%struct.bst* %23)
  store i32 %24, i32* @in, align 4
  ret i32 0
}

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.2 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str.4 = private unnamed_addr constant [17 x i8] c"Enter until zero\00", align 1
@.str.5 = private unnamed_addr constant [8 x i8] c"Inorder\00", align 1
@.str.6 = private unnamed_addr constant [9 x i8] c"Preorder\00", align 1
@.str.7 = private unnamed_addr constant [10 x i8] c"Postorder\00", align 1
@opt = common global i32 0,align 4
@in = common global i32 0,align 4

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

declare i8* @malloc(i64)

declare i32 @free(...)

declare void @llvm.memcpy.p0i8.p0i8.i32(i8*, i8*, i32, i1)
