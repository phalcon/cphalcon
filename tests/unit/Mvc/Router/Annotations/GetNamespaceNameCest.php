<?php

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

class GetNamespaceNameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: getNamespaceName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsGetNamespaceName(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Annotations - getNamespaceName()");
        $I->skipTest("Need implementation");
    }
}
