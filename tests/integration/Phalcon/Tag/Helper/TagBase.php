<?php
/**
 * TagBase.php
 * Phalcon\Tag\Helper\TagBase
 *
 * Tests the \Phalcon\Tag database components
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\integration\Phalcon\Tag;

use \Phalcon\DI as PhDI;
use \Phalcon\Tag as PhTag;

use \PhalconTest\Models\Select;
use \Codeception\TestCase\Test as CdTest;

class TagBase extends CdTest
{
    /**
     * @var \IntegrationTester
     */
    protected $tester;

    /**
     * Tests an image tag with a bare minimum of information passed
     *
     * @author Nikolaos Dimopoulos <nikos@niden.net>
     * @since  2014-10-17
     */
    public function notestSelectBasic()
    {
//        $user = new User();
//        $user->setName('Miles');
//        $user->setSurname('Davis');
//        $user->save();
//        $this->assertEquals('Miles Davis', $user->getFullName());
//        $this->unitTester->seeInDatabase('users',array('name' => 'Miles', 'surname' => 'Davis'));


        $select = Select::find();

        $params = array(
            'some_name',
            $select,
            'using' => array('id', 'name')
        );

        $expected = '<select name="some_name" id="some_name">' . PHP_EOL
                  . chr(9) . '<option value="1">Robotina</option>' . PHP_EOL
                  . chr(9) . '<option value="2">Astro Boy</option>' . PHP_EOL
                  . chr(9) . '<option value="3">Terminator</option>' . PHP_EOL
                  . '</select>';
        $actual   = PhTag::select($params);

        $this->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'select basic')
        );
    }

    protected function setDb($dbType = 'mysql')
    {
        $di = PhDI::getDefault();

        $config = $di['config'];

        $this->di->set(
            'db',
            function () use ($dbType, $config) {

                $params = $config['app_db_test'];
                $params['adapter'] = ucfirst($dbType);
                $class  = '\Phalcon\Db\Adapter\Pdo\\' . ucfirst($dbType);
                $conn   = new $class($params);

                return $conn;
            }
        );
    }
}
