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

namespace Phalcon\Test\Unit\Db\Adapter;

use UnitTester;

/**
 * Class SupportSequencesCest
 */
class SupportSequencesCest
{
    /**
     * Tests Phalcon\Db\Adapter :: supportSequences()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbAdapterSupportSequences(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter - supportSequences()');
        $I->skipTest('Need implementation');
    }
}
