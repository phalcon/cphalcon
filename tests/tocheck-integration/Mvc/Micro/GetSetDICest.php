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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\Micro;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Micro :: getDI()/setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro - getDI()/setDI()");

        $micro = new Micro();

        $this->newDi();

        $micro->setDI(
            $this->container
        );

        $I->assertInstanceOf(
            Di::class,
            $micro->getDI()
        );
    }
}
