int isValidArray(string &s, size_t pos);
int isValidJson(string &s, size_t pos);

bool isWhiteSpace(char c)
{
  if (c == ' ' || c == '\t')
  {
    return true;
  }
  return false;
}

/**
 * return position of open bracket
 * if no open bracket, return -1
 */
int isValidOpenBracket(string &s, size_t pos)
{
  // make sure the first non ws char is '{'
  for (size_t i = pos; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] != '{')
      {
        return -1;
      }
      else
      {
        return i + 1;
      }
    }
  }
  return -1;
}

int isValidCloseBracket(string &s, size_t pos)
{
  for (size_t i = pos; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] == '}')
      {
        return i + 1;
      }
      else
      {
        return -1;
      }
    }
  }
  return -1;
}

bool isAlphaNumeric(char c)
{
  if (c >= '0' && c <= '9')
  {
    return true;
  }

  if (c >= 'a' && c <= 'z')
  {
    return true;
  }

  if (c >= 'A' && c <= 'Z')
  {
    return true;
  }

  return false;
}

/**
 * "sldfjsdlkf"
 * "sldfjsldfj\"sdfsdf"
 */
int isValidStringLiteral(string &s, size_t pos)
{
  // skip whitespaces
  // double quote
  // characters
  // double quote
  size_t i = pos;
  for (; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      break;
    }
  }
  if (s[i] != '"')
  {
    return -1;
  }
  for (++i; i < s.length(); ++i)
  {
    if (s[i] == '"')
    {
      return i + 1;
    }
    else
    {
      if (!isAlphaNumeric(s[i]))
      {
        return -1;
      }
    }
  }

  return -1;
}

int isValidColon(string &s, size_t pos)
{
  size_t i = pos;
  for (; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] != ':')
      {
        return -1;
      }
      else
      {
        return i + 1;
      }
    }
  }
  return -1;
}

int isValidArrayBracket(string &s, size_t pos, char c)
{
  for (size_t i = pos; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] != c)
      {
        return -1;
      }
      else
      {
        return i + 1;
      }
    }
  }
  return -1;
}

/**
 *    array item
        -> literal
        -> array
        -> json
 */
int isValidArrayItem(string &s, size_t pos)
{
  int position = isValidStringLiteral(s, pos);
  if (position != -1)
  {
    return position; // TODO
  }
  position = isValidArray(s, pos);
  if (position != -1)
  {
    return position; // TODO
  }
  position = isValidJson(s, pos);
  if (position != -1)
  {
    return position; // TODO
  }

  return -1;
}

int isValidComma(string &s, size_t pos)
{
  for (size_t i = pos; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] == ',')
      {
        return i + 1;
      }
      else if (s[i] == ']')
      {
        return i;
      }
      else
      {
        return -1;
      }
    }
  }
  return -1;
}

/**
 * []
 * validate [
 * validate array item
 *    array item
        -> literal
        -> array
        -> json
 */
int isValidArray(string &s, size_t pos)
{
  // validate open array bracket
  int position = isValidArrayBracket(s, pos, '[');
  if (position == -1)
  {
    return -1;
  }
  while (position != -1)
  {
    // validate key value pairs
    // TODO close_position
    // TODO check for multiple key pairs
    position = isValidArrayItem(s, position);
    if (position == -1)
    {
      return -1;
    }
    position = isValidComma(s, position);
    if (position == -1)
    {
      return -1;
    }
    position = isValidArrayBracket(s, position, ']');
    if (position != -1)
    {
      return position;
    }
  }
  return -1;
}

/**
 * string literal
 * array
 * valid json
 */
int isValidValue(string &s, size_t pos)
{
  int position = isValidStringLiteral(s, pos);
  if (position != -1)
  {
    return position;
  }

  position = isValidArray(s, pos);
  if (position != -1)
  {
    return position;
  }

  position = isValidJson(s, pos);
  if (position != -1)
  {
    return position;
  }

  return -1;
}

int isValidKeyValuePair(string &s, size_t pos)
{
  // if i get close bracket, return true
  // validate a key
  // validate a ':'
  // validate a value
  for (size_t i = pos; i < s.length(); ++i)
  {
    if (!isWhiteSpace(s[i]))
    {
      if (s[i] == '}')
      { // TODO check this logic again
        return i;
      }
      else
      {
        int position;
        position = isValidStringLiteral(s, i);
        if (position == -1)
        {
          return -1;
        }
        position = isValidColon(s, position);
        if (position == -1)
        {
          return -1;
        }
        position = isValidValue(s, position);
        if (position == -1)
        {
          return -1;
        }
        return position;
      }
    }
  }

  return -1;
}

// "[1, 2]"
int isValidJson(string &s, size_t pos)
{
  // {
  // "xyz" - no
  if (s.empty())
  { // TODO
    return 0;
  }

  // validate for an open bracket
  // get the position of open bracket
  int position = isValidOpenBracket(s, pos);
  if (position == -1)
  {
    return -1;
  }
  while (position != -1)
  {
    // validate key value pairs
    // TODO close_position
    // TODO check for multiple key pairs
    position = isValidKeyValuePair(s, position);
  }

  // validate close bracket
  position = isValidCloseBracket(s, position);
  if (position != -1)
  {
    return position;
  }

  return -1;
}

bool solution(string jsonString)
{
}
