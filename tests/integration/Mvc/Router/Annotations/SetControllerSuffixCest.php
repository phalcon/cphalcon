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

namespace Phalcon\Test\Integration\Mvc\Router\Annotations;

use IntegrationTester;

/**
 * Class SetControllerSuffixCest
 */
class SetControllerSuffixCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: setControllerSuffix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsSetControllerSuffix(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Annotations - setControllerSuffix()');
        $I->skipTest('Need implementation');
    }
}
