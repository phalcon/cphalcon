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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug\ReportBuilder;
use Phalcon\Support\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\BackupGlobals;

#[BackupGlobals(true)]
final class ReportBuilderTest extends AbstractUnitTestCase
{
    public function testMetaWithoutBacktrace(): void
    {
        $exception = new Exception('boom', 7);
        $report    = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            false,
            true,
            false,
            'https://cdn/',
            []
        );

        $this->assertSame(Exception::class, $report->getClassName());
        $this->assertSame('boom', $report->getMessage());
        $this->assertSame('https://cdn/', $report->getUri());
        $this->assertSame([], $report->getBacktrace());
    }

    public function testRequestBlacklistIsApplied(): void
    {
        $_REQUEST['DATA_REQUEST_TEST'] = 'secret';
        $_SERVER['DATA_SERVER_TEST']   = 'keepme';

        $report = (new ReportBuilder())->build(
            new Exception('boom', 7),
            ['request' => ['data_request_test' => 1], 'server' => []],
            true,
            true,
            false,
            'https://cdn/',
            []
        );

        $this->assertArrayNotHasKey('DATA_REQUEST_TEST', $report->getRequest());
        $this->assertArrayHasKey('DATA_SERVER_TEST', $report->getServer());
        $this->assertGreaterThan(0, $report->getMemoryUsage());
        $this->assertGreaterThan(0, $report->getPeakMemoryUsage());
    }

    public function testInternalFunctionLinkIsResolved(): void
    {
        $exception = new Exception('placeholder');

        try {
            array_map(
                static function () {
                    throw new Exception('boom', 7);
                },
                [1]
            );
        } catch (Exception $e) {
            $exception = $e;
        }

        $report = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            true,
            false,
            false,
            'https://cdn/',
            []
        );

        $found = false;
        foreach ($report->getBacktrace() as $item) {
            $link = $item->getFunctionLink();
            if (null !== $link && str_contains($link, '/function.')) {
                $found = true;
                break;
            }
        }

        $this->assertTrue($found);
    }

    public function testLinkResolution(): void
    {
        $builder = new ReportBuilder();

        $classLink = new \ReflectionMethod(ReportBuilder::class, 'resolveClassLink');

        $this->assertStringContainsString(
            'docs.phalcon.io',
            $classLink->invoke($builder, 'Phalcon\\Mvc\\Model')
        );
        $this->assertStringContainsString(
            'secure.php.net/manual/en/class.',
            $classLink->invoke($builder, 'ArrayObject')
        );
        $this->assertNull($classLink->invoke($builder, 'PHPUnit\\Framework\\TestCase'));

        $functionLink = new \ReflectionMethod(ReportBuilder::class, 'resolveFunctionLink');

        $this->assertStringContainsString(
            'secure.php.net/manual/en/function.',
            $functionLink->invoke($builder, 'array_map')
        );
        $this->assertNull($functionLink->invoke($builder, 'phalcon_undefined_function_xyz'));
        $this->assertNull($functionLink->invoke($builder, 'supportDir'));
    }

    public function testBuildFragmentForUnreadableFile(): void
    {
        $builder = new ReportBuilder();

        $method = new \ReflectionMethod(ReportBuilder::class, 'buildFragment');

        $fragment = @$method->invoke($builder, '/phalcon/no/such/file.php', 5, false);

        $this->assertSame([], $fragment['lines']);
    }
}
