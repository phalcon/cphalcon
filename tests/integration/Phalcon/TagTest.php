<?php
namespace Phalcon;
use Codeception\Util\Stub;

class TagSelectTest extends \Codeception\TestCase\Test
{
   /**
    * @var \DbGuy
    */
    protected $dbGuy;

    public function _before()
    {
        $this->dbGuy->emptyTable('robots_parts');
        $this->dbGuy->populateTable('robots');
        $this->dbGuy->populateTable('robots_parts');
    }

    public function testTagSelect()
    {
        expect(
            Tag::select(array(
                'some_name',
                \Robots::find(),
                'using' => array('id', 'name')
            ))
        )->equals(
            '<select name="some_name" id="some_name">' . PHP_EOL
            . chr(9) . '<option value="1">Robotina</option>' . PHP_EOL
            . chr(9) . '<option value="2">Astro Boy</option>' . PHP_EOL
            . chr(9) . '<option value="3">Terminator</option>' . PHP_EOL
            . '</select>'
        );
    }

}