--TEST--
Incorrect results from Phalcon\Paginator\Adapter\Model - https://github.com/phalcon/cphalcon/issues/1654
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

function dump_page($page)
{
	$page->items = $page->items[0]; // Because Resultsets are weird and advance the current position in valid() not in next()
	print_r($page);
}

class Test implements SeekableIterator, Countable
{
	private $data = array(
		 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	);

	private $pos = 0;

	public function seek($pos)
	{
		$this->pos = $pos;
	}

	public function rewind()
	{
		$this->pos = 0;
	}

	public function current()
	{
		return $this->data[$this->pos];
	}

	public function key()
	{
		return $this->pos;
	}

	public function next()
	{
		++$this->pos;
	}

	public function valid()
	{
		return isset($this->data[$this->pos]);
	}

	public function count()
	{
		return count($this->data);
	}
}

$config = array(
	'limit' => 5,
	'page'  => 1,
	'data'  => new Test(),
);

$pager = new \Phalcon\Paginator\Adapter\Model($config);
for ($page=1; $page<=6; ++$page) {
	dump_page($pager->setCurrentPage($page)->getPaginate());
}
?>
--EXPECT--
stdClass Object
(
    [items] => 0
    [next] => 2
    [first] => 1
    [before] => 1
    [current] => 1
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
stdClass Object
(
    [items] => 5
    [next] => 3
    [first] => 1
    [before] => 1
    [current] => 2
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
stdClass Object
(
    [items] => 10
    [next] => 4
    [first] => 1
    [before] => 2
    [current] => 3
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
stdClass Object
(
    [items] => 15
    [next] => 4
    [first] => 1
    [before] => 3
    [current] => 4
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
stdClass Object
(
    [items] => 0
    [next] => 2
    [first] => 1
    [before] => 1
    [current] => 1
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
stdClass Object
(
    [items] => 0
    [next] => 2
    [first] => 1
    [before] => 1
    [current] => 1
    [last] => 4
    [total_pages] => 4
    [total_items] => 20
)
