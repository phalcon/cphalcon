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

namespace Phalcon\Tests\Benchmarks\Encryption;

use Phalcon\Di\Di;
use Phalcon\Encryption\Security\JWT\Builder;
use Phalcon\Encryption\Security\JWT\Signer\Hmac;
use Phalcon\Encryption\Security\JWT\Token\Parser;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

/**
 * The time claims are fixed, so the token is the same on each call.
 */
#[BeforeMethods('setUp')]
#[Revs(200)]
final class JwtBench
{
    private const EXPECTED_TOKEN = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiJ9'
        . '.eyJhdWQiOlsiaHR0cHM6Ly9waGFsY29uLmlvIl0sImV4cCI6NDEwMjQ0NDgwMCwianRpIjoiYmVuY2gtMSIsImlhdCI6'
        . 'MTcwMDAwMDAwMCwiaXNzIjoiaHR0cHM6Ly9waGFsY29uLmlvIiwibmJmIjoxNzAwMDAwMDAwLCJzdWIiOiJiZW5jaCJ9'
        . '.F_CWXOsTMdZz_bXLYj9MxwpfcpXUNZrPCob1zR0AHwWqoHr2yNNTVgji7L7AfVnWAXtxcEn0usXWdxwkKVE3rQ';

    private const PASSPHRASE = 'Phalcon!Bench#Passphrase2026';

    private Parser $parser;

    private Hmac $signer;

    public function setUp(): void
    {
        Di::reset();

        $this->parser = new Parser();
        $this->signer = new Hmac();
    }

    public function benchBuild(): void
    {
        $builder = new Builder($this->signer);
        $builder
            ->setAudience('https://phalcon.io')
            ->setExpirationTime(4102444800)
            ->setId('bench-1')
            ->setIssuedAt(1700000000)
            ->setIssuer('https://phalcon.io')
            ->setNotBefore(1700000000)
            ->setPassphrase(self::PASSPHRASE)
            ->setSubject('bench');

        $actual = $builder->getToken()->getToken();

        if (self::EXPECTED_TOKEN !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $actual));
        }
    }

    public function benchParse(): void
    {
        $actual = $this->parser->parse(self::EXPECTED_TOKEN)->getClaims()->get('sub');

        if ('bench' !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }
}
