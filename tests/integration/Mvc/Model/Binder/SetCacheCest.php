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

namespace Phalcon\Test\Integration\Mvc\Model\Binder;

use IntegrationTester;

/**
 * Class SetCacheCest
 */
class SetCacheCest
{
    /**
     * Tests Phalcon\Mvc\Model\Binder :: setCache()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelBinderSetCache(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Binder - setCache()');
        $I->skipTest('Need implementation');
    }
}
