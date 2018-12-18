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

namespace Phalcon\Test\Unit\Acl\Subject;

use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Subject :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectToString(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - __toString()');
        $subject = new Subject('Customers');

        $expected = 'Customers';
        $actual   = $subject->__toString();
        $I->assertEquals($expected, $actual);

        $expected = 'Customers';
        $actual   = (string) $subject;
        $I->assertEquals($expected, $actual);
    }
}
