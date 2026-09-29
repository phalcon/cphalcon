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

namespace Phalcon\Tests\Benchmarks\Http;

use Phalcon\Http\Response;
use Phalcon\Tests\Benchmarks\Apps\Rest\Fixture;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ResponseBench
{
    /**
     * The same content as the list of the REST app.
     */
    private const EXPECTED_JSON_SHA1 = '4a63cad4e32d423c8cc1e605a4d97d1475552dea';

    private const EXPECTED_SEND = 'Hello World';

    private array $rows = [];

    public function setUp(): void
    {
        $this->rows = (new Fixture())->rows(20);
    }

    /**
     * A response with a header, sent into an output buffer.
     */
    public function benchSend(): void
    {
        $response = new Response();
        $response->setContent(self::EXPECTED_SEND);
        $response->setHeader('X-Benchmark', '1');

        ob_start();
        $response->send();
        $body = ob_get_clean();

        if (self::EXPECTED_SEND !== $body) {
            throw new RuntimeException(sprintf('Unexpected body: "%s"', $body));
        }
    }

    /**
     * JSON content of 20 rows.
     */
    public function benchSetJsonContent(): void
    {
        $content = (string) (new Response())->setJsonContent($this->rows)->getContent();
        $actual  = sha1($content);

        if (self::EXPECTED_JSON_SHA1 !== $actual) {
            throw new RuntimeException(sprintf('Unexpected content (sha1 %s): %s', $actual, $content));
        }
    }
}
