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

class HttpMethodHandler
{
    public function delete()
    {
        return 'this is delete';
    }

    public function get()
    {
        return 'this is get';
    }

    public function head()
    {
        return 'this is head';
    }

    public function options()
    {
        return 'this is options';
    }

    public function patch()
    {
        return 'this is patch';
    }

    public function post()
    {
        return 'this is post';
    }

    public function put()
    {
        return 'this is put';
    }
}
