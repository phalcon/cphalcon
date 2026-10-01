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

namespace Phalcon\Tests\Benchmarks\Apps\Adr;

use Phalcon\ADR\Application;
use Phalcon\ADR\Container\AdrProvider;
use Phalcon\Container\ContainerFactory;
use Phalcon\Http\Request;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

/**
 * Reference app: ADR with the convention router. Each call is one request.
 */
#[BeforeMethods('setUp')]
#[Revs(100)]
final class AdrBench
{
    private const EXPECTED = 'hello world';

    public function setUp(): void
    {
        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_SERVER['REQUEST_URI']    = '/hello/world';
    }

    public function benchHello(): void
    {
        $container = (new ContainerFactory())
            ->addProvider(new AdrProvider())
            ->newContainer();

        $application = (new Application($container))
            ->setBaseNamespace(__NAMESPACE__ . '\\Action')
            ->setActionDirectory(__DIR__ . '/Action');

        ob_start();
        $application->handle(new Request())->send();
        $body = ob_get_clean();

        if (self::EXPECTED !== $body) {
            throw new RuntimeException(sprintf('Unexpected body: "%s"', $body));
        }
    }
}
