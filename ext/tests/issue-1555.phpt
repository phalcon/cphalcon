--TEST--
The use route converter and beforeMatch for Router\Group - https://github.com/phalcon/cphalcon/issues/1555
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

function addstars($s)
{
	return '*' . $s . '*';
}

$router = new \Phalcon\Mvc\Router(false);
$blog   = new \Phalcon\Mvc\Router\Group(array('module' => 'blog', 'controller' => 'index'));

$blog->setPrefix('/blog');

$blog->add('/delete/{id}', array('action' => 'delete'));
$blog->add('/edit/{id}',   array('action' => 'edit'));

$blog->convert('id', 'addstars');
$blog->convert('xx', 'strtolower');

var_dump($blog->getConverters());

$router->mount($blog);

$routes = $router->getRoutes();
assert(count($routes) == 2);

$route = $routes[0];
var_dump($route->getConverters());

$route = $routes[1];
var_dump($route->getConverters());

?>
--EXPECT--
array(2) {
  ["id"]=>
  string(8) "addstars"
  ["xx"]=>
  string(10) "strtolower"
}
array(2) {
  ["id"]=>
  string(8) "addstars"
  ["xx"]=>
  string(10) "strtolower"
}
array(2) {
  ["id"]=>
  string(8) "addstars"
  ["xx"]=>
  string(10) "strtolower"
}
