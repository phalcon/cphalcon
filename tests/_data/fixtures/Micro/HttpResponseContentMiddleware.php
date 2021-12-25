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

namespace Phalcon\Tests\Fixtures\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\MiddlewareInterface;

class HttpResponseContentMiddleware implements MiddlewareInterface
{
    public function call(Micro $application)
    {
        $body = ['test' => 123];
        $application
            ->response
            ->setStatusCode(404)
            ->setContentType('application/json', 'UTF-8')
            ->setJsonContent($body, JSON_NUMERIC_CHECK)
            ->send();

        $application->stop();
    }
}
