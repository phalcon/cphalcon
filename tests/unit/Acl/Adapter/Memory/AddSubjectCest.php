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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use UnitTester;

/**
 * Class AddSubjectCest
 *
 * @package Phalcon\Test\Unit\Acl\Adapter\Memory
 */
class AddSubjectCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubject()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubject()');
        $I->skipTest('Need implementation');
    }
}
