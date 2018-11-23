<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\NativeArray;

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\NativeArray;
use UnitTester;

class OffsetExistsCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: offsetExists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testOffsetExists(UnitTester $I)
    {
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $actual = $translator->offsetExists('hi');
        $I->assertTrue($actual);
    }
}
