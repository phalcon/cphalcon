<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

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
class TagSetDefaultTest extends UnitTest
{
    /**
     * Tests setDefault
     *
     * @issue  2402
     * @author Dmitry Patsura <talk@dmtry.me>
     * @since  2014-05-10
     */
    public function testDisplayValues()
    {
        $this->specify(
            "setDefault does not assigns default values to generated tags by helpers",
            function () {
                $tag = new Tag();

                $tag->setDefault('property1', 'testVal1');
                $tag->setDefault('property2', 'testVal2');
                $tag->setDefault('property3', 'testVal3');

                expect($tag->hasValue('property1'))->true();
                expect($tag->hasValue('property2'))->true();
                expect($tag->hasValue('property3'))->true();
                expect($tag->hasValue('property4'))->false();

                expect($tag->getValue('property1'))->equals('testVal1');
                expect($tag->getValue('property2'))->equals('testVal2');
                expect($tag->getValue('property3'))->equals('testVal3');
            }
        );
    }
}
