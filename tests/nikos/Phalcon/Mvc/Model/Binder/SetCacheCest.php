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

namespace Phalcon\Test\Unit\Mvc\Model\Binder;

use UnitTester;

class SetCacheCest
{
    /**
     * Tests Phalcon\Mvc\Model\Binder :: setCache()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcModelBinderSetCache(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Binder - setCache()');

        $I->skipTest('Need implementation');
    }
}
