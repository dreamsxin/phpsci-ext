--TEST--
Use-after-free bug demo for CArray::destroy()
--FILE--
<?php
$a = CArray::fromArray([[0,1],[2,3]]);
CArray::destroy($a->uuid, 2, 2);
print_r(CArray::toArray($a->uuid, 2, 2));
// should print nothing here
?>
--EXPECT--
Array
(
    [0] => Array
        (
            [0] => 0
            [1] => 0
        )

    [1] => Array
        (
            [0] => 2
            [1] => 3
        )

)