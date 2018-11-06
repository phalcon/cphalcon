<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

/**
 * \Phalcon\Test\Unit\Tag\TagSetDefaultTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagSetDefaultTest extends TagBase
{
    /**
     * Tests setDefault
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2402
     * @author Dmitry Patsura <talk@dmtry.me>
     * @since  2014-05-10
     */
    public function testDisplayValues(UnitTester $I)
    {
        $this->specify(
            "setDefault does not assigns default values to generated tags by helpers",
            function (UnitTester $I) {
                Tag::setDefault('property1', 'testVal1');
                Tag::setDefault('property2', 'testVal2');
                Tag::setDefault('property3', 'testVal3');

                expect(Tag::hasValue('property1'))->true(UnitTester $I);
                expect(Tag::hasValue('property2'))->true(UnitTester $I);
                expect(Tag::hasValue('property3'))->true(UnitTester $I);
                expect(Tag::hasValue('property4'))->false(UnitTester $I);

                expect(Tag::getValue('property1'))->equals('testVal1');
                expect(Tag::getValue('property2'))->equals('testVal2');
                expect(Tag::getValue('property3'))->equals('testVal3');
            }
        );
    }
}
