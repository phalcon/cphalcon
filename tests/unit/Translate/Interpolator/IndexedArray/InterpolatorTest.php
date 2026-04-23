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

namespace Phalcon\Tests\Unit\Translate\Interpolator\IndexedArray;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\InterpolatorFactory;

final class InterpolatorTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateInterpolatorIndexedArrayInterpolator(): void
    {

        $language = ['Hello!'          => 'Привет!',
                     'Hello %s %s %s!' => 'Привет, %s %s %s!',];

        $params = ['content'             => $language,
                   'defaultInterpolator' => 'indexedArray',];

        $translator = new NativeArray(new InterpolatorFactory(), $params);

        $actual = $translator->_('Hello %s %s %s!', ['John',
                                                     'D.',
                                                     'Doe',]);

        $this->assertSame('Привет, John D. Doe!', $actual);
    }
}
