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
use Phalcon\Tests\Unit\Translate\Fake\TranslateNativeArrayHelperTrait;
use Phalcon\Tests\Unit\Translate\Fake\TranslateNativeArrayTrait;

final class QueryTest extends AbstractUnitTestCase
{
    use TranslateNativeArrayTrait;
    use TranslateNativeArrayHelperTrait;

    /**
     * @return string
     */
    protected function func(): string
    {

        return 'query';
    }
}
