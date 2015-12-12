<?php

use Bookshelf\Books;

class CollectionsClassChangeTest extends PHPUnit_Framework_TestCase
{
	/** @var Books */
	protected $_book;

	public function __construct()
	{
		spl_autoload_register(array($this, 'collectionsAutoloader'));
	}

	public function __destruct()
	{
		spl_autoload_unregister(array($this, 'collectionsAutoloader'));
	}

	public function collectionsAutoloader($className)
	{
		$className = str_replace('\\', '/', $className);
		if (file_exists('unit-tests/collections/' . $className . '.php')) {
			require 'unit-tests/collections/' . $className . '.php';
		}
	}

	public static function setUpBeforeClass() {
		Phalcon\DI::reset();

		$di = new Phalcon\DI();

		$di->set('mongo', function(){
			$mongo = new MongoClient();
			return $mongo->phalcon_test;
		});

		$di->set('collectionManager', function(){
			return new Phalcon\Mvc\Collection\Manager();
		});
	}

	public function setUp() {
		$book = new Books();
		$book->title = 'book';
		$book->save();

		$this->_book = $book;
	}

	public function testCollectionsClassChange() {
		if (!class_exists('Mongo')) {
			$this->markTestSkipped("Mongo class does not exist, test skipped");
			return;
		}

		$book = Books::findFirst([['_id' => $this->_book->getId()]]);
		$this->assertInstanceOf('\Bookshelf\Books', $book);

		$magazine = Books::findFirst([
			['_id'   => $this->_book->getId()],
			'class' => '\Bookshelf\Magazines'
		]);
		$this->assertInstanceOf('\Bookshelf\Magazines', $magazine);

		$document = Books::findFirst([
			['_id'   => $this->_book->getId()],
			'class' => '\Phalcon\Mvc\Collection\Document'
		]);
		$this->assertInstanceOf('\Phalcon\Mvc\Collection\Document', $document);
	}

	public function testCollectionsClassChangeExceptionOnWrongClass() {
		if (!class_exists('Mongo')) {
			$this->markTestSkipped("Mongo class does not exist, test skipped");
			return;
		}

		$this->setExpectedException('Exception', 'must be an implementation of Phalcon\\Mvc\\CollectionInterface');

		Books::findFirst([
			['_id'   => $this->_book->getId()],
			'class' => '\Bookshelf\NotACollection'
		]);

	}

	public function tearDown() {
		$this->_book->delete();
	}

}