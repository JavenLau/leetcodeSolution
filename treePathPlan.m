clc

% data  = [1 1 2 2 3 3 6;
%             2 3 4 5 6 7 8]';        
% label = [2 3 5 6];
% num1 = sum( data(:,1) == 1 );
% num = 7;

% data = [1 1 1;
%            2 3 4]';
% label = [2 3 4];
% num1 = sum( data(:,1) == 1 );
% num = 3;

data = [1 1 1 2 2 3 3 3 4 9;
           2 3 4 5 6 7 8 9 10 11]';
label = [2 3 4 6 9 10 11];
num1 = sum( data(:,1) == 1 );
num = 10;

%construct tree
tree = data(1:num1,:);
[~, last] = size(tree);
tree_temp = [tree, zeros(num1,1)];
for i = num1+1:num
    if( isempty(find(tree(:,last)==data(i,1))) )       
        tree = tree_temp;
        last = last+1;
        [num2, ~] = size(tree);
        tree_temp = [tree, zeros(num2,1)];
    end
    c = find(tree(:,last)==data(i,1));
    temp = [tree(c,:), data(i,2)];
    tree_temp = [tree_temp; temp];
end
tree_temp;

%construct apple tree
tree_value = tree_temp;
for i = 1:sum(label~=0)
    tree_value(tree_value==label(i))=11111;
end;
tree_value(tree_value~=11111)=0;
tree_value(tree_value==11111)=1;
tree_value;
tree_value_sum = sum(tree_value, 2);

max_value = [];
for i = 2:num1+1
    temp = [];
    if(find(tree_temp(:,2)==i))
        temp = find(tree_temp(:,2)==i)';
        [~,t]=max(tree_value_sum(temp));
        max_value=[max_value temp(t)];
        tree_temp(temp(t),:)
    end;
end;
tree_value_sum(max_value)

        







