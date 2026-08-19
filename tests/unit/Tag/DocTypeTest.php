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
use PHPUnit\Framework\Attributes\DataProvider;

use const PHP_EOL;

/**
 * Covers Tag::setDocType() and Tag::getDocType().
 *
 * Every constant maps to one declaration, and the two HTML5 flavors share one.
 * A value outside the constant range is clamped to HTML5 on the way in, so the
 * `default` arm of the match is only reachable by writing the property
 * directly - which is what the last test does.
 */
final class DocTypeTest extends AbstractTagTestCase
{
    /**
     * @return array<array-key, array{0: int, 1: string}>
     */
    public static function getDocTypes(): array
    {
        return [
            [
                Tag::HTML32,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
                . PHP_EOL,
            ],
            [
                Tag::HTML401_STRICT,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/strict.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::HTML401_TRANSITIONAL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/loose.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::HTML401_FRAMESET,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::HTML5,
                "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                Tag::XHTML10_STRICT,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::XHTML10_TRANSITIONAL,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::XHTML10_FRAMESET,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::XHTML11,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::XHTML20,
                "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\""
                . PHP_EOL
                . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">"
                . PHP_EOL,
            ],
            [
                Tag::XHTML5,
                "<!DOCTYPE html>" . PHP_EOL,
            ],
        ];
    }

    /**
     * @return array<array-key, array{0: int}>
     */
    public static function getOutOfRangeDocTypes(): array
    {
        return [
            [Tag::HTML32 - 1],
            [Tag::XHTML5 + 1],
            [-100],
            [100],
        ];
    }

    #[DataProvider('getDocTypes')]
    public function testGetDocType(int $docType, string $expected): void
    {
        Tag::setDocType($docType);

        $this->assertSame($expected, Tag::getDocType());
    }

    public function testGetDocTypeWithUnknownTypeIsEmpty(): void
    {
        $this->setProtectedProperty(Tag::class, 'documentType', 99);

        $this->assertSame('', Tag::getDocType());
    }

    #[DataProvider('getOutOfRangeDocTypes')]
    public function testSetDocTypeOutOfRangeFallsBackToHtml5(int $docType): void
    {
        Tag::setDocType($docType);

        $this->assertSame('<!DOCTYPE html>' . PHP_EOL, Tag::getDocType());
    }
}
