<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Collection;

use IntegrationTester;
use MongoDB\Database;
use Phalcon\Test\Fixtures\Mvc\Collections\Robots;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetMessagesCest
 */
class GetMessagesCest
{
    use DiTrait;

    /** @var string $source */
    private $source;

    /** @var Database $mongo */
    private $mongo;

    public function _before()
    {
        $this->setNewFactoryDefault();
        $this->setDiCollectionManager();
        $this->setDiMongo();

        $this->source = (new Robots)->getSource();
        $this->mongo = $this->getDi()->get('mongo');
    }

    /**
     * Tests Phalcon\Mvc\Collection :: getMessages()
     *
     * @param IntegrationTester $I
     * @since  2018-11-13
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function mvcCollectionGetMessages(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Collection - getMessages()');

        $robot = new Robots;
        $robot->setProtectedField("bad");

        $I->assertFalse($robot->save());
        $I->assertNotEmpty($robot->getMessages());
    }

    public function _after()
    {
        $this->mongo->dropCollection($this->source);
    }
}
