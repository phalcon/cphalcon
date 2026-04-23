<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Translate\Adapter\NativeArray;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\TranslateNativeArrayTrait;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\InterpolatorFactory;

final class ArrayAccessTest extends AbstractUnitTestCase
{
    use TranslateNativeArrayTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterNativeArrayWithArrayAccess(): void
    {

        $language = $this->getArrayConfig()['ru'];

        $translator = new NativeArray(new InterpolatorFactory(), ['content' => $language,]);

        $actual = isset($translator['Hello!']);
        $this->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $this->assertFalse($actual);

        $expected = $language['Hello!'];
        $actual   = $translator['Hello!'];
        $this->assertSame($expected, $actual);
    }
}
