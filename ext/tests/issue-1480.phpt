--TEST--
Annotations with \ do not get parsed correctly
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

/**
 * @ORM\Table("test", ["id", "name", "created"])
 * @Routing\Route("/foo/bar")
 */
class Test {
	public function fooBar()
	{
	}
}

$reader      = new \Phalcon\Annotations\Adapter\Memory();
$reflector   = $reader->get('Test');
$annotations = $reflector->getClassAnnotations();

foreach ($annotations as $annotation) {
	echo $annotation->getName(), PHP_EOL;
	echo $annotation->numberArguments(), PHP_EOL;
	var_dump($annotation->getArguments());
}
?>
--EXPECT--
ORM\Table
2
array(2) {
  [0]=>
  string(4) "test"
  [1]=>
  array(3) {
    [0]=>
    string(2) "id"
    [1]=>
    string(4) "name"
    [2]=>
    string(7) "created"
  }
}
Routing\Route
1
array(1) {
  [0]=>
  string(8) "/foo/bar"
}

