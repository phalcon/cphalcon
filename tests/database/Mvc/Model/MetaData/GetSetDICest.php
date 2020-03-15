<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model\MetaData;

use DatabaseTester;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData :: getDI() / setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group common
     */
    public function mvcModelMetadataGetSetDI(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData - getDI() / setDI()');

        $metadata = new Memory();

        $I->assertNull($metadata->getDI());

        $metadata->setDI($this->container);

        $I->assertEquals($this->container, $metadata->getDI());
    }
}
