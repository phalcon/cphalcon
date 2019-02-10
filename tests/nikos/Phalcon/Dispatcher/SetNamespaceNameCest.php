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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;

/**
 * Class SetNamespaceNameCest
 */
class SetNamespaceNameCest
{
    /**
     * Tests Phalcon\Dispatcher :: setNamespaceName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dispatcherSetNamespaceName(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - setNamespaceName()');
        $I->skipTest('Need implementation');
    }
}
