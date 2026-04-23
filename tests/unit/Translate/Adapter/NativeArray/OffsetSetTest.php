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
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

final class OffsetSetTest extends AbstractUnitTestCase
{
    use TranslateNativeArrayTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterNativeArrayOffsetSet(): void
    {

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Translate is an immutable ArrayAccess object');

        $language = $this->getArrayConfig()['en'];

        $translator = new NativeArray(new InterpolatorFactory(), ['content' => $language,]);

        $translator->offsetSet('team', 'Team');
    }
}
