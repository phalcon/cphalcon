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

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class GetSubjectsCest
 */
class GetSubjectsCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getSubjects()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSubjects(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getSubjects()');
        $acl = new Memory();

        $subject1 = new Subject('Posts');
        $subject2 = new Subject('Tags');

        $acl->addSubject($subject1, ['index']);
        $acl->addSubject($subject2, ['index']);

        $expected = [$subject1, $subject2];
        $actual   = $acl->getSubjects();
        $I->assertEquals($expected, $actual);
    }
}
