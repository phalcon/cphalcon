<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Tag as Tag;

class TagTest extends PHPUnit_Framework_TestCase
{

	public function testSetTitleSeparator()
	{

		Tag::setTitle('Title');
		Tag::appendTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>TitleClass</title>'.PHP_EOL);

		Tag::setTitle('Title');
		Tag::setTitleSeparator('|');
		Tag::appendTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>Title|Class</title>'.PHP_EOL);
		$this->assertEquals(Tag::getTitleSeparator(), '|');

		Tag::setTitle('Title');
		Tag::setTitleSeparator('|');
		Tag::prependTitle('Class');

		$this->assertEquals(Tag::getTitle(), '<title>Class|Title</title>'.PHP_EOL);
	}
}
