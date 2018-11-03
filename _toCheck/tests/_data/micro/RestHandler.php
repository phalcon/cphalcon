<?php

class RestHandler
{
    protected $_access = 0;

    protected $_trace = [];



    public function find()
    {
        $this->_access++;
        $this->_trace[] = "find";
    }

    public function save()
    {
        $this->_access++;
        $this->_trace[] = "save";
    }

    public function delete()
    {
        $this->_access++;
        $this->_trace[] = "delete";
    }

    public function getNumberAccess()
    {
        return $this->_access;
    }

    public function getTrace()
    {
        return $this->_trace;
    }
}
