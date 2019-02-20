from datetime import datetime

class PostcardList:
    """
    class used to read/write postcards sender/receiver/date info.
    """
    def __init__(self):

        self._file = ""
        self._postcards = list()
        self._date = dict()
        self._from = dict()
        self._to = dict()

    def readFile(self, filename):
        """
        :param filename: file to read from
        ----------------------------------------------------------------------------------------------
        readFile first resets PostcardList parameters, then reads from filename and stores its lines
        as a list in self._postcards. It then call self._parsePostcards() to parse the lines contents.
        """
        self._file = filename

        #reset parameters
        self._postcards = list()
        self._date = dict()
        self._from = dict()
        self._to = dict()

        #read lines from file and append to self._postcards
        with open(self._file, "r") as file:
            for line in file:
                self._postcards.append(line)
        file.close()
        self.parsePostcards()



    def writeFile(self, filename):
        """

        :param filename: file to write to
        -------------------------------------------------------------------------------------
        writeFile write postcards stored in self._postcards list into filename, one for line.
        """

        with open(filename, 'w') as file:
            for line in self._postcards:
                file.write(line)
        file.close()

    def updateFile(self):
        """

        updateFile update postcards of the file in use by calling writeFile with self._file as argument
        """

        self.writeFile(self._file)

    def updateLists(self, filename):
        """

        :param filename: file to read from
        ---------------------------------------------------------------------------------------------------------------
        same as readFile but appending to self._postcards.
        Don't reset parameters, just updates them by appending new contents when self.parsePostcards() is called.

        """
        self._file = filename
        with open(self._file, 'r') as file:
            for line in file:
                self._postcards.append(line)
        file.close()
        self.parsePostcards()



    def parsePostcards(self):
        """
        parsePostcards is called by readFile and updateLists in order to parse the lines stored in self.postcards
        and append only postcards information (date, from, to) to their respectively dictionaries.
        Dictionaries have the above postcard information as key, and a list of indexes as a value, that represent
        the lines of the file where that postcard information occurs.

        """
        #i is the index of the file lines number
        for i in range(len(self._postcards)):

             #postcards information sanitized and retrieved
             date, fr, to = self._postcards[i].split(" ")
             date = date[5:15]
             fr = fr[5:-1]
             to = to[3:-2]
             date = datetime.strptime(date, '%Y-%m-%d')

             #postcards information written in corresponding dictionaries.
             # Conditional used to avoid error of key not found
             if date not in self._date:
                 self._date[date] = list()
             self._date[date].append(i)

             if fr not in self._from:
                 self._from[fr] = list()
             self._from[fr].append(i)

             if to not in self._to:
                 self._to[to] = list()
             self._to[to].append(i)



    def getNumberOfPostcards(self):
        """
        return length of file
        """
        return len(self._postcards)



    def getPostcardsByDateRange(self, date_range):
        """

        :param date_range: range of dates used to find postcards of interest
        :return: date_postcards, list of postcards found that match query
        --------------------------------------------------------------------------------------------------------------
        getPostcardsByDateRange parse the date list to retrieve the dates that belongs in the date_range of interest,
        the matches are retrieved from self._postcards and appended to date_postcards, that is returned to the user.
        """
        date_postcards = list()

        for date in self._date:
            if date_range[0] <= date <= date_range[1]:
                for d in self._date[date]:
                    date_postcards.append(self._postcards[d])
        return date_postcards



    def getPostcardsBySender(self, sender):
        """

        :param sender: sender used to find postcards of interest
        :return: sender_postcards, list of postcards found that match query
        --------------------------------------------------------------------------------------------------------------
        getPostcardsBySender parse the sender list to retrieve the sender of interest,
        the matches are retrieved from self._postcards and appended to sender_postcards, that is returned to the user.
        """
        sender_postcards = list()

        if sender in self._from:
            for s in self._from[sender]:
                sender_postcards.append(self._postcards[s])
        return sender_postcards



    def getPostcardsByReceiver(self, receiver):
        """

        :param receiver: receiver used to find postcards of interest
        :return: receiver_postcards, list of postcards found that match query
        ------------------------------------------------------------------------------------------------------------
        getPostcardsByReceiver parse the receiver list to retrieve the receiver of interest,
        the matches are retrieved from self._postcards and appended to receiver_postcards, that is returned to the user.
        """
        receiver_postcards = list()

        if receiver in self._to:
            for r in self._to[receiver]:
                receiver_postcards.append(self._postcards[r])
        return receiver_postcards








