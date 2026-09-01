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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Tag;

/**
 * Covers Tag::friendlyTitle(), a thin wrapper over the Str\Friendly helper.
 */
final class FriendlyTitleTest extends AbstractTagTestCase
{
    public function testFriendlyTitle(): void
    {
        $this->assertSame(
            'mary-had-a-little-lamb',
            Tag::friendlyTitle('Mary had a little lamb')
        );
    }

    public function testFriendlyTitleWithReplaceArray(): void
    {
        $this->assertSame(
            'm-ry-h-d-little-l-mb',
            Tag::friendlyTitle('Mary had a little lamb', '-', true, ['a'])
        );
    }

    public function testFriendlyTitleWithReplaceString(): void
    {
        $this->assertSame(
            'm-ry-h-d-little-l-mb',
            Tag::friendlyTitle('Mary had a little lamb', '-', true, 'a')
        );
    }

    public function testFriendlyTitleWithSeparatorAndCase(): void
    {
        $this->assertSame(
            'Mary_had_a_Little_Lamb',
            Tag::friendlyTitle('Mary had a Little Lamb', '_', false)
        );
    }
}
