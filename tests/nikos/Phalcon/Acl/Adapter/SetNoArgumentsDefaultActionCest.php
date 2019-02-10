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

namespace Phalcon\Test\Unit\Acl\Adapter;

use UnitTester;

/**
 * Class SetNoArgumentsDefaultActionCest
 */
class SetNoArgumentsDefaultActionCest
{
    /**
     * Tests Phalcon\Acl\Adapter :: setNoArgumentsDefaultAction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function aclAdapterSetNoArgumentsDefaultAction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter - setNoArgumentsDefaultAction()');
        $I->skipTest('Need implementation');
    }
}
