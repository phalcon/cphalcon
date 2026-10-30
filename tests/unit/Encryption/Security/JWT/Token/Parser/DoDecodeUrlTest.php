<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Parser;

use Phalcon\Encryption\Security\JWT\Token\Parser;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class DoDecodeUrlTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        // Input, Expected
        return [
            ['', ''],
            ['YQ', 'a'],
            ['YQ==', 'a'],
            ['YWI', 'ab'],
            ['YWJj', 'abc'],
            ['-_-_', "\xfb\xff\xbf"],
            ['YWJjé', 'abc'],
        ];
    }

    /**
     * Decodes a base64url string with or without padding.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/17705
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-29
     */
    #[DataProvider('getExamples')]
    public function testEncryptionSecurityJWTTokenParserDoDecodeUrl(
        string $input,
        string $expected
    ): void {
        $parser = new class () extends Parser {
            public static function decodeUrl(string $input): string
            {
                return self::doDecodeUrl($input);
            }
        };

        $this->assertSame($expected, $parser::decodeUrl($input));
    }
}
