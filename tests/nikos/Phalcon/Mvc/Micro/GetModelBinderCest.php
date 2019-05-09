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

namespace Phalcon\Test\Unit\Mvc\Micro;

use UnitTester;

class GetModelBinderCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: getModelBinder()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcMicroGetModelBinder(UnitTester $I)
    {
        $I->wantToTest('Mvc\Micro - getModelBinder()');

        $I->skipTest('Need implementation');
    }
}
