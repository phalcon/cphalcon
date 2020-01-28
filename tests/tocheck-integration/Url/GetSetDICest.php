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

namespace Phalcon\Test\Integration\Url;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Url;

class GetSetDICest
{
    /**
     * Tests Phalcon\Url :: getDI()/setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function urlGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Url - getDI()/setDI()');

        $url       = new Url();
        $container = new Di();

        $url->setDI($container);

        $actual = $url->getDI();

        $I->assertInstanceOf(
            Di::class,
            $actual
        );

        $I->assertEquals($container, $actual);
    }
}
