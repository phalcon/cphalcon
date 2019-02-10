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

namespace Phalcon\Test\Unit\Mvc\Router\Annotations;

use UnitTester;

/**
 * Class AddConnectCest
 */
class AddConnectCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: addConnect()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcRouterAnnotationsAddConnect(UnitTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - addConnect()');
        $I->skipTest('Need implementation');
    }
}
