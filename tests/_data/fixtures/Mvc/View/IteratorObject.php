<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Mvc\View;

class IteratorObject implements \Iterator, \Countable
{
    /**
     * @var array
     */
    private $data = [];

    /**
     * @var int
     */
    private $pointer = 0;

    public function __construct(array $data)
    {
        $this->data = $data;
    }

    public function count()
    {
        return count($this->data);
    }

    public function current()
    {
        return $this->data[$this->pointer];
    }

    public function key()
    {
        return $this->pointer;
    }

    public function next()
    {
        ++$this->pointer;
    }

    public function rewind()
    {
        $this->pointer = 0;
    }

    public function valid()
    {
        return $this->pointer < count($this->data);
    }
}
