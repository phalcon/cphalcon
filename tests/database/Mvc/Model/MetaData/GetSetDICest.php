<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model\MetaData;

use DatabaseTester;
use Phalcon\Mvc\Model\Exception as ExpectedException;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getDI() / setDI()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelMetadataGetSetDI(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getDI() / setDI()');

        $metadata = new Memory();
        $metadata->setDI($this->container);

        $I->assertEquals($this->container, $metadata->getDI());
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getDI() - exception
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-05
     *
     * @group  common
     */
    public function mvcModelMetadataGetDIThrowsException(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getDI() - exception');

        $I->expectThrowable(
            new ExpectedException(
                'A dependency injection container is required to access internal services'
            ),
            function () {
                (new Memory())->getDI();
            }
        );
    }
}
